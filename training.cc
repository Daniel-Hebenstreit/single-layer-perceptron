#include "lib.h"
#include <iostream>

double update_weights()
{
    // Eingabewerte. Erster Wert ist jeweils Bias(=1), vierter Wert ist jeweils korrekter bzw. erwarter Wert (true oder false)
    double matrix[3][4] = {{1, 2, 5, 1},  // i = 0
                           {1, 5, 4, 0},  // i = 1
                           {1, 3, 3, 0}}; // i = 2

    // Gewichte der Eingänge
    double weight[3] = {0, 0, 0};

    // Lernfaktor
    double alpha;
    std::cout << "Bitte Lernfaktor (zwischen 0 und 1) angeben: " << std::endl;
    std::cin >> alpha;

    // Aktualisierung der Gewichte
    for (int i = 0; i < 3; i++)
    {
        // Aktivierungsfunktion: Heaviside- bzw. Treppenfunktion H(x)
        double h1 = weight[0] * matrix[i][0] + weight[1] * matrix[i][1] + weight[2] * matrix[i][2]; // -> x
        int h2;                                                                                     // -> H(x)

        if (h1 < 0)
        {
            h2 = 0;
        }
        else
        {
            h2 = 1;
        }
        std::cout << "\nH(x) = " << h2 << std::endl;

        // Aktualisierung und Ausgabe der Gewichte
        for (int j = 0; j < 3; j++)
        {
            weight[j] = weight[j] + alpha * matrix[i][j] * (matrix[i][3] - h2);
            std::cout << "weight " << j << ": " << weight[j] << std::endl;
        }
    }
}
