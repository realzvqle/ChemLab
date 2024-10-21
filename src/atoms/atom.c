#include "atom.h"
#include <string.h>
#include <stdio.h>


Element periodic_table[] = {
    {1, "Hydrogen", {255, 0, 0, 255}},      {2, "Helium", {255, 127, 0, 255}},      {3, "Lithium", {255, 255, 0, 255}},      {4, "Beryllium", {0, 255, 0, 255}},  
    {5, "Boron", {0, 255, 255, 255}},       {6, "Carbon", {0, 0, 255, 255}},        {7, "Nitrogen", {75, 0, 130, 255}},       {8, "Oxygen", {148, 0, 211, 255}},     
    {9, "Fluorine", {255, 20, 147, 255}},    {10, "Neon", {255, 182, 193, 255}},      
    {11, "Sodium", {255, 165, 0, 255}},      {12, "Magnesium", {173, 216, 230, 255}}, {13, "Aluminum", {240, 230, 140, 255}},   {14, "Silicon", {139, 69, 19, 255}},   
    {15, "Phosphorus", {255, 255, 255, 255}}, {16, "Sulfur", {255, 255, 0, 255}},      {17, "Chlorine", {0, 128, 0, 255}},      {18, "Argon", {0, 255, 255, 255}},     
    {19, "Potassium", {128, 0, 128, 255}},    {20, "Calcium", {128, 128, 0, 255}},      
    {21, "Scandium", {64, 224, 208, 255}},    {22, "Titanium", {176, 196, 222, 255}},  {23, "Vanadium", {153, 50, 204, 255}},   {24, "Chromium", {255, 105, 180, 255}},  
    {25, "Manganese", {255, 127, 80, 255}},   {26, "Iron", {139, 28, 98, 255}},       {27, "Cobalt", {0, 191, 255, 255}},      {28, "Nickel", {178, 34, 34, 255}},    
    {29, "Copper", {255, 69, 0, 255}},        {30, "Zinc", {218, 165, 32, 255}},        
    {31, "Gallium", {169, 169, 169, 255}},    {32, "Germanium", {220, 220, 220, 255}}, {33, "Arsenic", {255, 160, 122, 255}},    {34, "Selenium", {255, 0, 255, 255}},  
    {35, "Bromine", {178, 34, 34, 255}},      {36, "Krypton", {135, 206, 250, 255}},    {37, "Rubidium", {255, 0, 0, 255}},      {38, "Strontium", {255, 20, 147, 255}},  
    {39, "Yttrium", {255, 0, 255, 255}},      {40, "Zirconium", {0, 139, 139, 255}},   
    {41, "Niobium", {160, 32, 240, 255}},     {42, "Molybdenum", {102, 205, 170, 255}}, {43, "Technetium", {0, 255, 0, 255}},    {44, "Ruthenium", {238, 130, 238, 255}}, 
    {45, "Rhodium", {139, 69, 19, 255}},      {46, "Palladium", {255, 218, 185, 255}},  {47, "Silver", {192, 192, 192, 255}},    {48, "Cadmium", {255, 215, 0, 255}},    
    {49, "Indium", {160, 82, 45, 255}},       {50, "Tin", {204, 204, 255, 255}},       
    {51, "Antimony", {178, 34, 34, 255}},     {52, "Tellurium", {0, 206, 209, 255}},   {53, "Iodine", {148, 0, 211, 255}},       {54, "Xenon", {173, 216, 230, 255}},     
    {55, "Cesium", {255, 215, 0, 255}},       {56, "Barium", {139, 69, 19, 255}},      {57, "Lanthanum", {70, 130, 180, 255}},   {58, "Cerium", {0, 191, 255, 255}},      
    {59, "Praseodymium", {178, 34, 34, 255}},  {60, "Neodymium", {255, 105, 180, 255}}, 
    {61, "Promethium", {255, 69, 0, 255}},     {62, "Samarium", {255, 160, 122, 255}},  {63, "Europium", {255, 20, 147, 255}},    {64, "Gadolinium", {220, 220, 220, 255}}, 
    {65, "Terbium", {0, 255, 0, 255}},        {66, "Dysprosium", {255, 0, 0, 255}},    {67, "Holmium", {75, 0, 130, 255}},       {68, "Erbium", {255, 182, 193, 255}},    
    {69, "Thulium", {255, 127, 0, 255}},      {70, "Ytterbium", {255, 0, 255, 255}},   
    {71, "Lutetium", {255, 105, 180, 255}},   {72, "Hafnium", {255, 165, 0, 255}},     {73, "Tantalum", {0, 128, 0, 255}},      {74, "Tungsten", {0, 255, 255, 255}},  
    {75, "Rhenium", {0, 0, 255, 255}},        {76, "Osmium", {75, 0, 130, 255}},       {77, "Iridium", {148, 0, 211, 255}},     {78, "Platinum", {255, 20, 147, 255}},  
    {79, "Gold", {255, 255, 0, 255}},         {80, "Mercury", {0, 0, 0, 255}},         
    {81, "Thallium", {139, 69, 19, 255}},     {82, "Lead", {178, 34, 34, 255}},        {83, "Bismuth", {255, 165, 0, 255}},     {84, "Polonium", {255, 127, 80, 255}},    
    {85, "Astatine", {255, 255, 0, 255}},     {86, "Radon", {148, 0, 211, 255}},       {87, "Francium", {255, 0, 255, 255}},    {88, "Radium", {255, 255, 255, 255}},    
    {89, "Actinium", {75, 0, 130, 255}},      {90, "Thorium", {0, 0, 255, 255}},       
    {91, "Protactinium", {0, 255, 0, 255}},   {92, "Uranium", {255, 0, 0, 255}},       {93, "Neptunium", {0, 128, 0, 255}},     {94, "Plutonium", {0, 255, 255, 255}},   
    {95, "Americium", {255, 20, 147, 255}},   {96, "Curium", {255, 127, 0, 255}},      {97, "Berkelium", {255, 255, 0, 255}},   {98, "Californium", {255, 255, 255, 255}}, 
    {99, "Einsteinium", {178, 34, 34, 255}},  {100, "Fermium", {0, 255, 0, 255}},    
    {101, "Mendelevium", {0, 0, 255, 255}},   {102, "Nobelium", {255, 69, 0, 255}},    {103, "Lawrencium", {255, 20, 147, 255}}, {104, "Rutherfordium", {75, 0, 130, 255}}, 
    {105, "Dubnium", {148, 0, 211, 255}},     {106, "Seaborgium", {0, 255, 255, 255}},  {107, "Bohrium", {255, 0, 0, 255}},      {108, "Hassium", {0, 255, 0, 255}},       
    {109, "Meitnerium", {0, 0, 255, 255}},    {110, "Darmstadtium", {255, 127, 0, 255}}, 
    {111, "Roentgenium", {0, 255, 0, 255}},   {112, "Copernicium", {0, 128, 0, 255}},  {113, "Nihonium", {0, 255, 255, 255}},    {114, "Flerovium", {255, 20, 147, 255}},  
    {115, "Moscovium", {0, 0, 255, 255}},     {116, "Livermorium", {255, 69, 0, 255}},  {117, "Tennessine", {255, 0, 0, 255}},    {118, "Oganesson", {255, 127, 80, 255}}   
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

// scuffed implemnation =(
uint8_t AtGetValenceElectrons(Atom* atom){
    if (atom->electrons <= 2) {
        return atom->electrons;  
    } else if (atom->electrons >= 3 && atom->electrons <= 10) {
        return atom->electrons; 
    } else if (atom->electrons >= 11 && atom->electrons <= 18) {
        return atom->electrons - 10;  
    } else {
        int group = (atom->electrons - 1) % 18; 
        if (group == 0) {
            return 8;  
        } else if (group <= 2) {
            return group;  
        } else if (group <= 4) {
            return 2;  
        } else if (group <= 6) {
            return group - 10;  
        } else if (group <= 8) {
            return 8;  
        } else if (group <= 10) {
            return group - 10; 
        } else {
            printf("Valence electron calculation for %d electrons isn't implemented.\n", atom->electrons);
            return 0;  
        }
    }
}