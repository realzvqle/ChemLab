#include "atom.h"
#include <string.h>
#include <stdio.h>


Element periodic_table[] = {
    {1, "Hydrogen", {255, 0, 0, 255}, 1}, {2, "Helium", {255, 127, 0, 255}, 2},

    {3, "Lithium", {255, 255, 0, 255}, 1}, {4, "Beryllium", {0, 255, 0, 255}, 2},
    {5, "Boron", {0, 255, 255, 255}, 3}, {6, "Carbon", {0, 0, 255, 255}, 4},
    {7, "Nitrogen", {75, 0, 130, 255}, 5}, {8, "Oxygen", {148, 0, 211, 255}, 6},
    {9, "Fluorine", {255, 20, 147, 255}, 7}, {10, "Neon", {255, 182, 193, 255}, 8},

    {11, "Sodium", {255, 165, 0, 255}, 1}, {12, "Magnesium", {173, 216, 230, 255}, 2},
    {13, "Aluminum", {240, 230, 140, 255}, 3}, {14, "Silicon", {139, 69, 19, 255}, 4},
    {15, "Phosphorus", {255, 255, 255, 255}, 5}, {16, "Sulfur", {255, 255, 0, 255}, 6},
    {17, "Chlorine", {0, 128, 0, 255}, 7}, {18, "Argon", {0, 255, 255, 255}, 8},

    {19, "Potassium", {128, 0, 128, 255}, 1}, {20, "Calcium", {128, 128, 0, 255}, 2},

    {21, "Scandium", {64, 224, 208, 255}, 3}, {22, "Titanium", {176, 196, 222, 255}, 4},
    {23, "Vanadium", {153, 50, 204, 255}, 5}, {24, "Chromium", {255, 105, 180, 255}, 6},
    {25, "Manganese", {255, 127, 80, 255}, 7}, {26, "Iron", {139, 28, 98, 255}, 8},
    {27, "Cobalt", {0, 191, 255, 255}, 9}, {28, "Nickel", {178, 34, 34, 255}, 10},
    {29, "Copper", {255, 69, 0, 255}, 1}, {30, "Zinc", {218, 165, 32, 255}, 2},

    {31, "Gallium", {169, 169, 169, 255}, 3}, {32, "Germanium", {220, 220, 220, 255}, 4},
    {33, "Arsenic", {255, 160, 122, 255}, 5}, {34, "Selenium", {255, 0, 255, 255}, 6},
    {35, "Bromine", {178, 34, 34, 255}, 7}, {36, "Krypton", {135, 206, 250, 255}, 8},

    {37, "Rubidium", {255, 0, 0, 255}, 1}, {38, "Strontium", {255, 20, 147, 255}, 2},
    {39, "Yttrium", {255, 0, 255, 255}, 3}, {40, "Zirconium", {0, 139, 139, 255}, 4},

    {41, "Niobium", {160, 32, 240, 255}, 5}, {42, "Molybdenum", {102, 205, 170, 255}, 6},
    {43, "Technetium", {0, 255, 0, 255}, 7}, {44, "Ruthenium", {238, 130, 238, 255}, 8},
    {45, "Rhodium", {139, 69, 19, 255}, 9}, {46, "Palladium", {255, 218, 185, 255}, 10},

    {47, "Silver", {192, 192, 192, 255}, 1}, {48, "Cadmium", {255, 215, 0, 255}, 2},
    {49, "Indium", {160, 82, 45, 255}, 3}, {50, "Tin", {204, 204, 255, 255}, 4},

    {51, "Antimony", {178, 34, 34, 255}, 5}, {52, "Tellurium", {0, 206, 209, 255}, 6},
    {53, "Iodine", {148, 0, 211, 255}, 7}, {54, "Xenon", {173, 216, 230, 255}, 8},

    {55, "Cesium", {255, 215, 0, 255}, 1}, {56, "Barium", {139, 69, 19, 255}, 2},

    {57, "Lanthanum", {70, 130, 180, 255}, 3}, {58, "Cerium", {0, 191, 255, 255}, 4},
    {59, "Praseodymium", {178, 34, 34, 255}, 5}, {60, "Neodymium", {255, 105, 180, 255}, 6},
    {61, "Promethium", {255, 69, 0, 255}, 7}, {62, "Samarium", {255, 160, 122, 255}, 8},

    {63, "Europium", {255, 20, 147, 255}, 8}, {64, "Gadolinium", {220, 220, 220, 255}, 9},
    {65, "Terbium", {0, 255, 0, 255}, 10}, {66, "Dysprosium", {255, 0, 0, 255}, 10},
    {67, "Holmium", {75, 0, 130, 255}, 11}, {68, "Erbium", {255, 182, 193, 255}, 12},
    {69, "Thulium", {255, 127, 0, 255}, 13}, {70, "Ytterbium", {255, 0, 255, 255}, 14},

    {71, "Lutetium", {255, 105, 180, 255}, 15}, {72, "Hafnium", {255, 165, 0, 255}, 4},
    {73, "Tantalum", {0, 128, 0, 255}, 5}, {74, "Tungsten", {0, 255, 255, 255}, 6},

    {75, "Rhenium", {0, 0, 255, 255}, 7}, {76, "Osmium", {75, 0, 130, 255}, 8},
    {77, "Iridium", {148, 0, 211, 255}, 9}, {78, "Platinum", {255, 20, 147, 255}, 10},

    {79, "Gold", {255, 255, 0, 255}, 1}, {80, "Mercury", {0, 0, 0, 255}, 2},

    {81, "Thallium", {139, 69, 19, 255}, 3}, {82, "Lead", {178, 34, 34, 255}, 4},
    {83, "Bismuth", {255, 165, 0, 255}, 5}, {84, "Polonium", {255, 127, 80, 255}, 6},
    {85, "Astatine", {255, 255, 0, 255}, 7}, {86, "Radon", {148, 0, 211, 255}, 8},
    {87, "Francium", {255, 0, 255, 255}, 1}, {88, "Radium", {255, 255, 255, 255}, 2},
    {89, "Actinium", {75, 0, 130, 255}, 3}, {90, "Thorium", {0, 0, 255, 255}, 4},
    {91, "Protactinium", {0, 255, 0, 255}, 5}, {92, "Uranium", {255, 0, 0, 255}, 6},
    {93, "Neptunium", {0, 128, 0, 255}, 5}, {94, "Plutonium", {0, 255, 255, 255}, 6},
    {95, "Americium", {255, 20, 147, 255}, 7}, {96, "Curium", {255, 127, 0, 255}, 8},
    {97, "Berkelium", {255, 255, 0, 255}, 3}, {98, "Californium", {255, 255, 255, 255}, 4},
    {99, "Einsteinium", {178, 34, 34, 255}, 5}, {100, "Fermium", {0, 255, 0, 255}, 6},
    {101, "Mendelevium", {0, 0, 255, 255}, 7}, {102, "Nobelium", {255, 69, 0, 255}, 2},
    {103, "Lawrencium", {255, 20, 147, 255}, 3}, {104, "Rutherfordium", {75, 0, 130, 255}, 4},
    {105, "Dubnium", {148, 0, 211, 255}, 5}, {106, "Seaborgium", {0, 255, 255, 255}, 6},
    {107, "Bohrium", {255, 0, 0, 255}, 7}, {108, "Hassium", {0, 255, 0, 255}, 8},
    {109, "Meitnerium", {0, 0, 255, 255}, 9}, {110, "Darmstadtium", {255, 127, 0, 255}, 10},
    {111, "Roentgenium", {0, 255, 0, 255}, 1}, {112, "Copernicium", {0, 128, 0, 255}, 2},
    {113, "Nihonium", {0, 255, 255, 255}, 3}, {114, "Flerovium", {255, 20, 147, 255}, 4},
    {115, "Moscovium", {0, 0, 255, 255}, 5}, {116, "Livermorium", {255, 69, 0, 255}, 6},
    {117, "Tennessine", {255, 0, 0, 255}, 7}, {118, "Oganesson", {255, 127, 80, 255}, 8}
};



char* AtReturnElementNameFromProtonNumber(int protonnum){
    if(protonnum > 118 || protonnum <= 0){
        printf("Failed to Find Element!\n");
        return NULL;
    }
    int num = protonnum - 1;
    return periodic_table[num].name;
}

uint8_t AtReturnProtonNumberFromElementName(char* Elementname){
    for(int i = 0; i < 118; i++){
        if(strcmp(periodic_table[i].name, Elementname) == 0){
            return i + 1;
        }
    }   
    printf("Failed to Find Element!\n");
    return 0;
}

Element AtReturnElementFromProtonNumber(int protonnum){
    if(protonnum > 118 || protonnum <= 0){
        printf("Failed to Find Element!\n");
        Element elm = {0, NULL, 0};
        return elm;
    }
    int num = protonnum - 1;
    return periodic_table[num];
}

Element AtReturnElementFromElementName(char* Elementname){
    for(int i = 0; i < 118; i++){
        if(strcmp(periodic_table[i].name, Elementname) == 0){
            return periodic_table[i];
        }
    }   
    printf("Failed to Find Element!\n");
    Element elm = {0, NULL, 0};
    return elm;
}


Atom AtInitializeAtom(uint8_t protons, uint8_t neutrons, uint8_t electrons){
    Atom atm;
    atm.element = AtReturnElementFromProtonNumber(protons);
    atm.electrons = electrons;
    atm.neutrons = neutrons;
    return atm;
}

// scuffed implemnation, doesn't even work =(
uint8_t AtGetValenceElectrons(Atom* atom){
    return atom->element.valence;
}