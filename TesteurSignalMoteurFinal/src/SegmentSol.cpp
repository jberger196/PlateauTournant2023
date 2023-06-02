/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SegmentSol.cpp
 * Author: snir2g2
 *
 * Created on 19 mars 2019, 15:24
 */

#include <iostream>

#include "../defs/SegmentSol.h"
#include "../defs/SegmentVol.h"
#include "../defs/serialib.h"
#include "../defs/FrameManager.h"
#include "../defs/Message.h"


using namespace std;

    mutex mutex_serial, mutex_message;
	//condition_variable cv;
	//bool ready = false;

SegmentSol::SegmentSol(SegmentVol *leSegment) {
    this->leSegment = leSegment;
    sem_init(&sync, 0, 0);
}

SegmentSol::~SegmentSol() {
}

void SegmentSol::activerReception() {
	serialib * monObjSerial = new serialib; //Déclaration de l'instance
	vector<char> laTrame;
	vector<char>::iterator it ;
    while (true) {
        monObjSerial->Open("/dev/serial0", 9600); //Ouverture
        char varID = leSegment->getIdentifiant();
		message->setIdSegment(varID);
        int typeRetourTrame = monObjSerial->ReadString(trameReception, 255, 128, 0);

		if (typeRetourTrame == -3) {
      envoyerInfos("BUSY");
        } else if (typeRetourTrame > 1) {
                if (trameReception[0] == varID)
				{
                    bool boolChecksum = this->verifierChecksum();
                    if (boolChecksum == true) {
						envoyerInfos("ACK");
                        this->ajouter_cmd_queue(trameReception);
                    }
					else {
						envoyerInfos("NACK");
                    }
                }
        }
    //Pas de commande reçue
		monObjSerial->Close();
    }
}





thread SegmentSol::tActiverReception() {
    return thread([this] {
        activerReception();
    });
}

void SegmentSol::envoyerStatus(list<string> status) {

    serialib LS;
    int Ret;
	bool argumentsOK=true;
    list<string>::iterator it;
	int nbrePaquets = 0;
    unsigned char idSegment = leSegment->getIdentifiant();
	mutex_message.lock();
    message->setIdSegment(idSegment);
    if (status.begin() == status.end()) {
        //ORDIBORD
        Stockage * leStockage = leSegment->getOrdinateur()->getStockage();
        std::size_t found = leStockage->getUnit().find('k');
        if (found != std::string::npos) {
            string USDenKilo = leStockage->getMemoireUSD();
            int FUSDenKilo = std::stoi(USDenKilo);
            int FUSDenMo = FUSDenKilo / 1024;
            message->setMicroSDenMo(to_string(FUSDenMo));
        }
        message->setTemperatureProc(leSegment->getOrdinateur()->getTemperatureProcessor());
        message->setMicroSDenMo(leStockage->getMemoireUSD());
        message->setRAMenPourcent(leStockage->getOccupationRAM());
        message->setDateOrdinateur(leSegment->getHorloge()->getDateHeure());
		//REBOOT
        message->setReboot(leSegment->getOrdinateur()->getReboot());
        //BATTERIE
        message->setAmperageBat(leSegment->getBatterie()->getAmperage());
        message->setCapacityBat(leSegment->getBatterie()->getCapacity());
        message->setChargeBat(leSegment->getBatterie()->getChargingLevel());
        message->setChargeStatus(leSegment->getBatterie()->getInCharge());
        message->setTemperatureBat(leSegment->getBatterie()->getTemperature());
        message->setVoltageBat(leSegment->getBatterie()->getVoltage());
        //INSTRUMENT
        message->setStatInstrument(leSegment->getInstrument()->getStatus());
        //CUBE
        message->setTemperatureCube(leSegment->getTemperature()->getTemperature());
		nbrePaquets = 2;

    } else for (it = status.begin(); it != status.end(); it++) {

            //ordinateur
            if (*it == TypeAppareil::ORDIBORD) {
                Stockage * leStockage = leSegment->getOrdinateur()->getStockage();
                std::size_t found = leStockage->getUnit().find('k');
                if (found != std::string::npos) {
                    string USDenKilo = leStockage->getMemoireUSD();
                    int FUSDenKilo = std::stoi(USDenKilo);
                    int FUSDenMo = FUSDenKilo / 1024;
                    message->setMicroSDenMo(to_string(FUSDenMo));
                }
                message->setTemperatureProc(leSegment->getOrdinateur()->getTemperatureProcessor());
                message->setMicroSDenMo(leStockage->getMemoireUSD());
                message->setRAMenPourcent(leStockage->getOccupationRAM());
                message->setDateOrdinateur(leSegment->getHorloge()->getDateHeure());
				nbrePaquets++;

            }//BATT
            else if (*it == TypeAppareil::BATTERIE) {
                message->setAmperageBat(leSegment->getBatterie()->getAmperage());
                message->setCapacityBat(leSegment->getBatterie()->getCapacity());
                message->setChargeBat(leSegment->getBatterie()->getChargingLevel());
                message->setChargeStatus(leSegment->getBatterie()->getInCharge());
                message->setTemperatureBat(leSegment->getBatterie()->getTemperature());
                message->setVoltageBat(leSegment->getBatterie()->getVoltage());
				nbrePaquets++;
            }//Instrument
            else if (*it == TypeAppareil::INSTRUMENT) {
                message->setStatInstrument(leSegment->getInstrument()->getStatus());
				nbrePaquets++;
            }//Cube
            else if (*it == TypeAppareil::CUBE) {
                message->setTemperatureCube(leSegment->getTemperature()->getTemperature());
				nbrePaquets++;
            }
			else if (*it == TypeAppareil::REBOOT) {
				message->setReboot(leSegment->getOrdinateur()->getReboot());
				if (message->getTemperatureCube() =="0") nbrePaquets++;
            }
			else {
				argumentsOK=false;
			}
        }

		//ready = true;
		//unique_lock<mutex> lck(mutex_serial);
		if (argumentsOK)
		{
			for (int i = 0; i < nbrePaquets; i++) {
			Ret = LS.Open(DEVICE_PORT, 9600);
			if (Ret >= 1) {

				tramerStatus(message, status, nbrePaquets, i + 1);
				Ret = LS.Write(trameEmission, trameEmission[1] + 5);
				LS.Close();
				}
			}
		}
		else {
				vector<char> laTrame = this->tramerRepAcq(message,"ERROR-E13");
				vector<char>::iterator it ;
				Ret = LS.Open(DEVICE_PORT, 9600);
				for (it = laTrame.begin(); it != laTrame.end() ; it++) {
					LS.WriteChar(*it);
				}
				LS.Close();

		}
    //cv.notify_all();
    //ready = false;
	message=new Message();
		mutex_message.unlock();
}

void SegmentSol::envoyerMission() {
  serialib LS;
  char Ret;
  unsigned char idSegment = leSegment->getIdentifiant();
  	mutex_message.lock();
  message->setIdSegment(idSegment);
  Instrument* instrument = leSegment->getInstrument();
  list<Mesure*> mesures = instrument->getMesures();
  message->setMesures(mesures);
  Mission * laMission = leSegment->getMission();
  string leTypeMission = laMission ->getMeasureType();
  message->setTypeMission(leTypeMission);
  int nbrePaquets = this->calculerNombrePaquets(message);
//	ready = true;
//std::unique_lock<std::mutex> lck(mutex_serial);

  for (int i = 0; i < nbrePaquets; i++) {
      Ret=LS.Open(DEVICE_PORT,9600);
      tramerMission(message, nbrePaquets, i+1);
      Ret = LS.Write(trameEmission, trameEmission[1] + 5);

      //auto start = std::chrono::high_resolution_clock::now();
      //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      //auto end = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double, std::milli> elapsed = end-start;
      //std::cout << "Waited " << elapsed.count() << " ms\n";
      LS.Close();
  }
//    cv.notify_all();
//    ready = false;
  	mutex_message.unlock();
  instrument->clearMesures();
  mesures = instrument->getMesures();

}

void SegmentSol::traiter_cmd_queue() {
while (true){
    sem_wait(&sync);
    if (q.size() > 0) {
      for (int i = 0; i < 100; i++) {
        trameAtraiter[i] = q.front()[i];
      }
      q.pop(); //Sortir la commande de la queue
      detramerCommande(); //Détramer la commande afin de la traiter en suivant l'encapsulation
      traiterCommande(); //Traiter la commande utile
    }
  }
}

void SegmentSol::traiterCommande() {



    //Traitement des commandes

    if (commande->getCode() == TypeCommande::MISSION) {

		list<string> mission = commande->getParametres();
                //VETUDIANT
		        //list<string> typeMission = commande->getParametres();
				//vector<string> vector_string;
                //   for (auto list : typeMission) {
                //        vector_string.push_back(list); //vector_string.at(5) = duree ,vector_string.at(6) = type ;
                //        }
                //        string duree = vector_string.at(3); //duree
                //        string periode = vector_string.at(1); //période
                //        int int_1 = stoi(duree);
                //        int int_2 = stoi(periode);

                //        (short)int_1 ;
                //        (short)int_2 ;

                //leSegment->creerMission(int_1,int_2,vector_string.at(5),vector_string.at(6)) ;
				short periodicity=0; ///////////////////////////
				short duration=0; ///////////////////////////
				string startTime=""; ///////////////////////////
				string measureType=""; ///////////////////////////
				list<string>::iterator itMission = mission.begin(); ///////////////////////////
				istringstream iss; ///////////////////////////

				for (itMission = mission.begin();itMission != mission.end();itMission++)
				{
					if ((*itMission) == TypeMisEtat::PERIOD) {
						iss = istringstream( *(++itMission) );
							iss >> periodicity;
	
					}
					else if ((*itMission) == TypeMisEtat::DURATION) {
						iss = istringstream( *(++itMission) );
						iss >> duration;
					}
					else if ((*itMission) == TypeMisEtat::DATETIME) {
									startTime = *(++itMission);
								}
					else measureType = *(itMission);
				}

				leSegment->creerMission(periodicity, duration, startTime, measureType); //(short periode, short duree, string debut, string type)

                thread lMission = leSegment->tLancerMission();
                lMission.detach();

    } else if (commande->getCode() == TypeCommande::DATE) {
		list<string> listeArguments = commande->getParametres();
		string theDate;
		unsigned char buffer[104];

		theDate= TypeCommande::DATE + TypeMisEtat::DATETIME;
		if (listeArguments.empty()) 
			{
				leSegment->getHorloge()->lire();
				theDate += leSegment->getHorloge()->getDateHeure();
				buffer[0]=theDate.size();
				strcpy((char*)&buffer[1], theDate.c_str());
				theDate =string((char*)buffer);
				this->envoyerInfos(theDate);
		}
		else 
		{
			bool save = false;
			size_t found;
			string newDate="";
			for (auto argument : listeArguments) {
				found = argument.find(TypeMisEtat::DATETIME);
				if (found!=std::string::npos)
				{
					newDate = ((string)argument).substr(found + TypeMisEtat::DATETIME.size());
					found = newDate.find('/'); 
					istringstream iss;
					int year, month, day, hour, minute, second;
					iss = istringstream(newDate.substr(0, found)); 
					iss>>year; 

					string leReste = newDate.substr(found + 1); 
					found = leReste.find('/'); 

					iss = istringstream(leReste.substr(0, found)); 
					iss>>month; 

					leReste = leReste.substr(found + 1);
					found = leReste.find(' ');

					iss = istringstream(leReste.substr(0, found)); 
					iss>>day;

					leReste = leReste.substr(found + 1);
					found = leReste.find(':'); 

					iss = istringstream(leReste.substr(0, found));
					iss>>hour; 

					leReste = leReste.substr(found + 1);
					found = leReste.find(':'); 
					iss = istringstream(leReste.substr(0, found));
					iss>>minute;


					iss = istringstream(leReste.substr(found + 1, 2));
					iss>>second; 
					leSegment->getHorloge()->initDateTime(day,month,year,hour,minute,second); //year, month, day, hour, minute, second;
				}
			}
		}
    } else if (commande->getCode() == TypeCommande::DEPLOY) {
        //à Voir
    } else if (commande->getCode() == TypeCommande::EMPTY) {
        leSegment->getOrdinateur()->getReboot()->systemeReboot();
    } else if (commande->getCode() == TypeCommande::MEASURE) {
        list<string> mesure = commande->getParametres();
        if (mesure.front() == TypeMisEtat::TEMPCELSIUS) {
            leSegment->effectuerMesure(TEMPCELSIUS);
        } else if (mesure.front() == TypeMisEtat::PIXEL) {
            leSegment->effectuerMesure(PIXEL);
        } else {
				envoyerInfos("ERROR-E11");
		}
    } else if (commande->getCode() == TypeCommande::MEETING) {
        //à Voir
    } else if (commande->getCode() == TypeCommande::SAVE) {
        //à Voir
    } else if (commande->getCode() == TypeCommande::STATUS) {
        list<string> status = commande->getParametres();
		leSegment->obtenirStatus(status);
    } else if (commande->getCode() == TypeCommande::SURVIVAL) {
        //à Voir
    } else
	{
				envoyerInfos("ERROR-E10");
	}
}


thread SegmentSol::tTraiter_cmd_queue() {
    return thread([this] {
        traiter_cmd_queue();
    });
}

void SegmentSol::envoyerMesure(string type) {
    serialib LS;
    int Ret;
    Instrument* instrument = leSegment->getInstrument();
    unsigned char idSegment = leSegment->getIdentifiant();
	mutex_message.lock();

    message->setIdSegment(idSegment);
	message->setTypeMesure(type);

    if (type.find(FrameManager::TEMPCELSIUS) != string::npos) {
        list<Mesure*> mesures = leSegment->getInstrument()->getMesures();
        message->setMesures(mesures);
        int nbrePaquets = 1;
		//ready = true;
		//unique_lock<mutex> lck(mutex_serial);
		//cv.notify_all();
        for (int i = 0; i < nbrePaquets; i++) {
            tramerMesure(message, nbrePaquets, 1);
			Ret = LS.Open(DEVICE_PORT, 9600);
            Ret = LS.Write(trameEmission, trameEmission[1] + 5);
            LS.Close();
        }
        message->clearMesures();
        instrument->clearLastMesures();
    } else if (type.find(FrameManager::PIXEL) != string::npos) {

        float * mesures = leSegment->getInstrument()->obtenirMesure();
        for (int i = 0; i < 64; i++) {
            message->addPixel(*(mesures + i));
        }
        int nbrePaquets = 8;
		//ready = true;
		//std::unique_lock<std::mutex> lck(mutex_serial);

        for (int i = 0; i < nbrePaquets; i++) {
            Ret = LS.Open(DEVICE_PORT, 9600);

            tramerMesure(message, nbrePaquets, i + 1);
            Ret = LS.Write(trameEmission, trameEmission[1] + 5);
            LS.Close();
        }
        message->clearPixels();
    }
          //cv.notify_all();
          //ready = false; //mutex_serial.unlock();

		mutex_message.unlock();

}

void SegmentSol::envoyerInfos(string type){
					message->setIdSegment(leSegment->getIdentifiant());
				vector<char> laTrame = this->tramerRepAcq(message,type);
				vector<char>::iterator it ;
				serialib LS;
				LS.Open(DEVICE_PORT, 9600);
				for (it = laTrame.begin(); it != laTrame.end() ; it++) {
					LS.WriteChar(*it);
				}
				LS.Close();
}
