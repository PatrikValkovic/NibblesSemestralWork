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
#include "../Exceptions/InvalidFormatException.h"

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
         * Container for headers of translation
         */
        struct AviableTranslations
        {
            /**
             * Name of file, where the translation was found
             */
            string File;
            /**
             * Shortcut of language
             */
            string Shortcut;
            /**
             * Fullname of language
             */
            string LanguageName;
        };

        /**
         * Container for current language in format map<statement,translation>
         */
        map<string,string> TranslationForCurrentLanguage;

        /**
         * Shortcut of current language
         */
        string CurrentLangauge;

        /**
         * Vector of file names, that contain translation
         */
        vector<string> TranslationFiles;

        /**
         * Vector of aviable translations
         */
        vector<AviableTranslations> Aviable;

        /**
         * Load all files in translation folder
         * @throw Exceptions::Exception if no directory found
         * @return Veector of file names in translation folder
         */
        vector<string> GetTranslateFiles() const;

        /**
         * Parse headers of translation files
         * @param Files Vector of file names, that contain translation
         * @return Vector of aviable translations
         */
        vector<AviableTranslations> ReadHeaders(vector<string> Files) const;

        /**
         * Load file, parse it and fill TranslationForCurrentLanguage map
         * @throw Exceptions::InvalidFormatException if is file in wrong format
         * @param Filename
         */
        void LoadTranslation(string Filename);
    };
}

#endif //CERVISEMESTRALKA_TRANSLATEENGINE_H
