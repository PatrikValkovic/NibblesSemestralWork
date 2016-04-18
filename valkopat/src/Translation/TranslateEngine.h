#ifndef CERVISEMESTRALKA_TRANSLATEENGINE_H
#define CERVISEMESTRALKA_TRANSLATEENGINE_H
#include <exception>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <dirent.h>
#include "../Exceptions/InvalidArgumentException.h"

using namespace std;

namespace Translate
{
    class TranslateEngine
    {
    public:
        TranslateEngine(string DefaultLanguage = "cz");

        string GetTranslation(string OriginalName) const;

        vector<string> GetAviablesLanguages() const;

        void SetLanguage(string CodeOfLanguage);

    private:
        struct AviableTranslations
        {
            string File;
            string Shortcut;
            string LanguageName;
        };

        map<string,string> TranslationForCurrentLanguage;
        string CurrentLangauge;
        vector<string> TranslationFiles;
        vector<AviableTranslations> Aviable;

        vector<string> GetTranslateFiles() const;
        vector<AviableTranslations> ReadHeaders(vector<string> Files) const;
        void LoadTranslation(string Filename);
    };
}

#endif //CERVISEMESTRALKA_TRANSLATEENGINE_H
