#include <stdio.h>
#include <stdlib.h>

// Gemeinsames Array mit 5 Einträgen (Index 0..4)
const char *names[] = {
    "test",
    "paul",
    "thomas",
    "anton",
    "secret"
};
const int TOTAL_NAMES = 5;  // Anzahl der Einträge im Array

void unsichere_variante(void) {
    int choice;

    printf("\n== Unsichere Variante ==\n");
    printf("Bitte wähle einen Namen (1–4):\n");
    // Nur die ersten vier Einträge sicht­bar machen
    for (int i = 0; i < 4; i++) {
        printf("  %d. %s\n", i + 1, names[i]);
    }

    printf("Deine Wahl: ");
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Ungültige Eingabe.\n");
        return;
    }

    // **Nur Untergrenze prüfen** (choice >= 1)
    if (choice >= 1) {
        // Bei choice == 5 → names[4] == "secret"
        // Bei choice >= 6 → names[choice-1] = out-of-bounds → Crash möglich
        printf("Ausgewählt: %s\n", names[choice - 1]);
    } else {
        printf("Auswahl nicht vorhanden.\n");
    }
}

void sichere_variante(void) {
    int choice;

    printf("\n== Sichere Variante ==\n");
    printf("Bitte wähle einen Namen (1–4):\n");
    // Wieder nur die ersten vier Einträge sicht­bar machen
    for (int i = 0; i < 4; i++) {
        printf("  %d. %s\n", i + 1, names[i]);
    }

    printf("Deine Wahl: ");
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Ungültige Eingabe.\n");
        return;
    }

    // **Obere und Untere Grenzprüfung** (1 ≤ choice ≤ 4)
    if (choice >= 1 && choice <= 4) {
        printf("Ausgewählt: %s\n", names[choice - 1]);
    } else {
        printf("Auswahl nicht vorhanden.\n");
    }
}

int main(void) {
    int variant;

    printf("Wähle Variante:\n");
    printf("  1. Unsichere Variante (grenzt nur unten)\n");
    printf("  2. Sichere Variante   (grenzt oben und unten)\n");
    printf("Deine Wahl: ");
    if (scanf("%d", &variant) != 1) {
        fprintf(stderr, "Ungültige Eingabe.\n");
        return EXIT_FAILURE;
    }

    switch (variant) {
        case 1:
            unsichere_variante();
            break;
        case 2:
            sichere_variante();
            break;
        default:
            printf("Ungültige Auswahl. Programm beendet.\n");
            break;
    }

    return EXIT_SUCCESS;
}
