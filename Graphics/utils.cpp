#include "utils.h"

string Utils::readFile(const string& filePath)
{
    //apre il file in modalità lettura seguendo il path
    ifstream file(filePath);
    if (!file) {
        cerr << "Errore: impossibile aprire il file " << filePath << endl;
        return "";
    }
    //crea un buffer di testo
    stringstream buffer;
    //legge il file e lo memorizza in buffer
    buffer << file.rdbuf();
    //restituisce il contenuto del file come stringa
    return buffer.str();
}
