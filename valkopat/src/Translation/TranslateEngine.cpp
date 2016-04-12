#include "TranslateEngine.h"

Translate::TranslateEngine::TranslateEngine(string DefaultLanguage)
{
    //this->SetLanguage(DefaultLanguage);
}

string Translate::TranslateEngine::GetTranslation(string OriginalName) const
{
    const map<string,string>::const_iterator iterator = this->TranslationForCurrentLanguage.find(OriginalName);
    if(iterator==TranslationForCurrentLanguage.end())
        throw new Exceptions::InvalidArgumentException("Translation not found",__LINE__,__FILE__);
    return iterator->second;
}



