#include "atom.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>


Element periodic_table[] = {
    {1, "HYDROGEN", {255, 0, 0, 255}, 1}, {2, "HELIUM", {255, 127, 0, 255}, 2},
    {3, "LITHIUM", {255, 255, 0, 255}, 1}, {4, "BERYLLIUM", {0, 255, 0, 255}, 2},
    {5, "BORON", {0, 255, 255, 255}, 3}, {6, "CARBON", {0, 0, 255, 255}, 4},
    {7, "NITROGEN", {75, 0, 130, 255}, 5}, {8, "OXYGEN", {148, 0, 211, 255}, 6},
    {9, "FLUORINE", {255, 20, 147, 255}, 7}, {10, "NEON", {255, 182, 193, 255}, 8},
    {11, "SODIUM", {255, 165, 0, 255}, 1}, {12, "MAGNESIUM", {173, 216, 230, 255}, 2},
    {13, "ALUMINUM", {240, 230, 140, 255}, 3}, {14, "SILICON", {139, 69, 19, 255}, 4},
    {15, "PHOSPHORUS", {255, 255, 255, 255}, 5}, {16, "SULFUR", {255, 255, 0, 255}, 6},
    {17, "CHLORINE", {0, 128, 0, 255}, 7}, {18, "ARGON", {0, 255, 255, 255}, 8},
    {19, "POTASSIUM", {128, 0, 128, 255}, 1}, {20, "CALCIUM", {128, 128, 0, 255}, 2},
    {21, "SCANDIUM", {64, 224, 208, 255}, 3}, {22, "TITANIUM", {176, 196, 222, 255}, 4},
    {23, "VANADIUM", {153, 50, 204, 255}, 5}, {24, "CHROMIUM", {255, 105, 180, 255}, 6},
    {25, "MANGANESE", {255, 127, 80, 255}, 7}, {26, "IRON", {139, 28, 98, 255}, 2},
    {27, "COBALT", {0, 191, 255, 255}, 2}, {28, "NICKEL", {178, 34, 34, 255}, 2},
    {29, "COPPER", {255, 69, 0, 255}, 1}, {30, "ZINC", {218, 165, 32, 255}, 2},
    {31, "GALLIUM", {169, 169, 169, 255}, 3}, {32, "GERMANIUM", {220, 220, 220, 255}, 4},
    {33, "ARSENIC", {255, 160, 122, 255}, 5}, {34, "SELENIUM", {255, 0, 255, 255}, 6},
    {35, "BROMINE", {178, 34, 34, 255}, 7}, {36, "KRYPTON", {135, 206, 250, 255}, 8},
    {37, "RUBIDIUM", {255, 0, 0, 255}, 1}, {38, "STRONTIUM", {255, 20, 147, 255}, 2},
    {39, "YTTRIUM", {255, 0, 255, 255}, 3}, {40, "ZIRCONIUM", {0, 139, 139, 255}, 4},

    {41, "NIOBIUM", {160, 32, 240, 255}, 5}, {42, "MOLYBDENUM", {102, 205, 170, 255}, 6},
    {43, "TECHNETIUM", {0, 255, 0, 255}, 7}, {44, "RUTHENIUM", {238, 130, 238, 255}, 8},
    {45, "RHODIUM", {139, 69, 19, 255}, 9}, {46, "PALLADIUM", {255, 218, 185, 255}, 10},

    {47, "SILVER", {192, 192, 192, 255}, 1}, {48, "CADMIUM", {255, 215, 0, 255}, 2},
    {49, "INDIUM", {160, 82, 45, 255}, 3}, {50, "TIN", {204, 204, 255, 255}, 4},

    {51, "ANTIMONY", {178, 34, 34, 255}, 5}, {52, "TELLURIUM", {0, 206, 209, 255}, 6},
    {53, "IODINE", {148, 0, 211, 255}, 7}, {54, "XENON", {173, 216, 230, 255}, 8},

    {55, "CESIUM", {255, 215, 0, 255}, 1}, {56, "BARIUM", {139, 69, 19, 255}, 2},

    {57, "LANTHANUM", {70, 130, 180, 255}, 3}, {58, "CERIUM", {0, 191, 255, 255}, 4},
    {59, "PRASEODYMIUM", {178, 34, 34, 255}, 5}, {60, "NEODYMIUM", {255, 105, 180, 255}, 6},
    {61, "PROMETHIUM", {255, 69, 0, 255}, 7}, {62, "SAMARIUM", {255, 160, 122, 255}, 8},

    {63, "EUROPIUM", {255, 20, 147, 255}, 2}, {64, "GADOLINIUM", {220, 220, 220, 255}, 9},
    {65, "TERBIUM", {0, 255, 0, 255}, 10}, {66, "DYSPROSIUM", {255, 0, 0, 255}, 10},
    {67, "HOLMIUM", {75, 0, 130, 255}, 11}, {68, "ERBIUM", {255, 182, 193, 255}, 12},
    {69, "THULIUM", {255, 127, 0, 255}, 13}, {70, "YTTERBIUM", {255, 0, 255, 255}, 2},

    {71, "LUTETIUM", {255, 105, 180, 255}, 15}, {72, "HAFNIUM", {255, 165, 0, 255}, 4},
    {73, "TANTALUM", {0, 128, 0, 255}, 5}, {74, "TUNGSTEN", {0, 255, 255, 255}, 6},

    {75, "RHENIUM", {0, 0, 255, 255}, 7}, {76, "OSMIUM", {75, 0, 130, 255}, 8},
    {77, "IRIDIUM", {148, 0, 211, 255}, 9}, {78, "PLATINUM", {255, 20, 147, 255}, 10},

    {79, "GOLD", {255, 255, 0, 255}, 1}, {80, "MERCURY", {0, 0, 0, 255}, 2},

    {81, "THALLIUM", {139, 69, 19, 255}, 3}, {82, "LEAD", {178, 34, 34, 255}, 4},
    {83, "BISMUTH", {255, 165, 0, 255}, 5}, {84, "POLONIUM", {255, 127, 80, 255}, 6},
    {85, "ASTATINE", {255, 255, 0, 255}, 7}, {86, "RADON", {148, 0, 211, 255}, 8},
    {87, "FRANCIUM", {255, 0, 255, 255}, 1}, {88, "RADIUM", {255, 255, 255, 255}, 2},
    {89, "ACTINIUM", {75, 0, 130, 255}, 3}, {90, "THORIUM", {0, 0, 255, 255}, 4},
    {91, "PROTACTINIUM", {0, 255, 0, 255}, 5}, {92, "URANIUM", {255, 0, 0, 255}, 6},
    {93, "NEPTUNIUM", {0, 128, 0, 255}, 5}, {94, "PLUTONIUM", {0, 255, 255, 255}, 6},
    {95, "AMERICIUM", {255, 20, 147, 255}, 7}, {96, "CURIUM", {255, 127, 0, 255}, 8},
    {97, "BERKELIUM", {255, 255, 0, 255}, 3}, {98, "CALIFORNIUM", {255, 255, 255, 255}, 4},
    {99, "EINSTEINIUM", {178, 34, 34, 255}, 5}, {100, "FERMIUM", {0, 255, 0, 255}, 6},
    {101, "MENDELEVIUM", {0, 0, 255, 255}, 7}, {102, "NOBELIUM", {255, 69, 0, 255}, 2},
    {103, "LAWRENCIUM", {255, 20, 147, 255}, 3}, {104, "RUTHERFORDIUM", {75, 0, 130, 255}, 4},
    {105, "DUBNIUM", {148, 0, 211, 255}, 5}, {106, "SEABORGIUM", {0, 255, 255, 255}, 6},
    {107, "BOHRIUM", {255, 0, 0, 255}, 7}, {108, "HASSIUM", {0, 255, 0, 255}, 8},
    {109, "MEITNERIUM", {0, 0, 255, 255}, 9}, {110, "DARMSTADTIUM", {255, 127, 0, 255}, 10},
    {111, "ROENTGENIUM", {0, 255, 0, 255}, 1}, {112, "COPERNICIUM", {0, 128, 0, 255}, 2},
    {113, "NIHONIUM", {0, 255, 255, 255}, 3}, {114, "FLEROVIUM", {255, 20, 147, 255}, 4},
    {115, "MOSCOVIUM", {0, 0, 255, 255}, 5}, {116, "LIVERMORIUM", {255, 69, 0, 255}, 6},
    {117, "TENNESSINE", {255, 0, 0, 255}, 7}, {118, "OGANESSON", {255, 127, 80, 255}, 8}
};



char* AtReturnElementNameFromProtonNumber(int protonnum){
    if(protonnum > 118 || protonnum <= 0){
        assert("Out of Bounds!\n");
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
    return 0;
}

Element AtReturnElementFromProtonNumber(int protonnum){
    if(protonnum > 118 || protonnum <= 0){
        assert("Out of Bounds!\n");
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