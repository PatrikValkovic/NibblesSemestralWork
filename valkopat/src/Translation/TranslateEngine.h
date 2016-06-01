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
    /**
     * TranslateEngine is used to translate application between different languages
     */
    class TranslateEngine
    {
    public:

        /**
         * Create new instance of TranslateEngine with translation to language specifies by parameter
         * @param DefaultLanguage Language to translate by default, default value is "cz"
         * @throw Exceptions::InvalidArgumentException if translation for language don't exists
         * @return New instance of TranslateEngine
         */
        TranslateEngine(string DefaultLanguage = "cz");

        /**
         * Get translate for string
         * @param OriginalName string in the format in which it is specified in the translation files
         * @throw Exceptions::InvalidArgumentException if OriginalName don't have translation
         * @return Translated string into setted language
         */
        string GetTranslation(string OriginalName) const;

        /**
         * Find all languages files and return languages generated
         * @return map<string,string> of languages in format map<shortcut,full name of language>
         */
        map<string,string> GetAviablesLanguages() const;

        /**
         * Change language to translate
         * @throw Exceptions::InvalidArgumentException if language with that code don't exists
         * @param CodeOfLanguage Language to translate next statements
         */
        void SetLanguage(string CodeOfLanguage);

        /**
         * Return name of current language
         * @return Name of current language
         */
        string GetActualLanguage() const;

    private:
        /**
         *
         */
        struct AviableTranslations
        {
            /**
             *
             */
            string File;
            /**
             *
             */
            string Shortcut;
            /**
             *
             */
            string LanguageName;
        };

        /**
         *
         */
        map<string,string> TranslationForCurrentLanguage;

        /**
         *
         */
        string CurrentLangauge;

        /**
         *
         */
        vector<string> TranslationFiles;

        /**
         *
         */
        vector<AviableTranslations> Aviable;

        /**
         *
         * @return
         */
        vector<string> GetTranslateFiles() const;

        /**
         *
         * @param Files
         * @return
         */
        vector<AviableTranslations> ReadHeaders(vector<string> Files) const;

        /**
         *
         * @param Filename
         */
        void LoadTranslation(string Filename);
    };
}

#endif //CERVISEMESTRALKA_TRANSLATEENGINE_H
