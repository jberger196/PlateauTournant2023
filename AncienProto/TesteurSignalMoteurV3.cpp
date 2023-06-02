#include <libsoc_gpio.h>
#include <unistd.h>

int main()
{
    // Initialiser les GPIO pour les entrées
    // Demander l'accès au GPIO numéro 1 et le partager avec d'autres programmes
    gpio *gpio_input1 = libsoc_gpio_request(GPIO_NUMBER_1, LS_SHARED);
    // Demander l'accès au GPIO numéro 2 et le partager avec d'autres programmes
    gpio *gpio_input2 = libsoc_gpio_request(GPIO_NUMBER_2, LS_SHARED);
    // Définir la direction du GPIO numéro 1 comme entrée
    libsoc_gpio_set_direction(gpio_input1, INPUT);
    // Définir la direction du GPIO numéro 2 comme entrée
    libsoc_gpio_set_direction(gpio_input2, INPUT);

    // Boucle pour lire les entrées toutes les 120 millisecondes
    while (1)
    {
        // Récupérer le niveau logique du GPIO numéro 1
        int level1 = libsoc_gpio_get_level(gpio_input1);
        // Récupérer le niveau logique du GPIO numéro 2
        int level2 = libsoc_gpio_get_level(gpio_input2);
        // Afficher le niveau logique du GPIO numéro 1
        printf("GPIO %d: %d\n", GPIO_NUMBER_1, level1);
        // Afficher le niveau logique du GPIO numéro 2
        printf("GPIO %d: %d\n", GPIO_NUMBER_2, level2);

        // Mettre en pause l'exécution du programme pendant 120 millisecondes
        usleep(120 * 1000);
    }

    // Libérer les GPIO
    // Libérer l'accès au GPIO numéro 1
    libsoc_gpio_free(gpio_input1);
    // Libérer l'accès au GPIO numéro 2
    libsoc_gpio_free(gpio_input2);

    return 0;
}