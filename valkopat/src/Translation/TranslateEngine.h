#ifndef CERVISEMESTRALKA_TRANSLATEENGINE_H
#define CERVISEMESTRALKA_TRANSLATEENGINE_H
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace Translate
{
    class TranslateEngine
    {
    public:
        TranslateEngine(string DefaultLanguage = "cs");

        string GetTranslation(string OriginalName) const;

        vector<string> GetAviablesLanguages() const;

        void SetLanguage(string CodeOfLanguage);

    private:
        map<string,string> TranslationForCurrentLanguage;
        string CurrentLangauge;
    };
}

#endif //CERVISEMESTRALKA_TRANSLATEENGINE_H
