#include "TranslateEngine.h"
#include <iostream>

Translate::TranslateEngine::TranslateEngine(string DefaultLanguage)
{
    this->TranslationFiles = GetTranslateFiles();
    this->Aviable = this->ReadHeaders(this->TranslationFiles);
}

string Translate::TranslateEngine::GetTranslation(string OriginalName) const
{
    const map<string,string>::const_iterator iterator = this->TranslationForCurrentLanguage.find(OriginalName);
    if(iterator==TranslationForCurrentLanguage.end())
        throw new Exceptions::InvalidArgumentException("Translation not found",__LINE__,__FILE__);
    return iterator->second;
}

vector<string> Translate::TranslateEngine::GetTranslateFiles() const
{
    DIR* DataDirectory = opendir("./data/Translate");
    if(DataDirectory==NULL)
        throw new Exceptions::Exception("Directory for translation not found",__LINE__,__FILE__);
    vector<string> Files;
    struct dirent* DirEntry;
    while((DirEntry = readdir(DataDirectory)) != NULL)
        if(DirEntry->d_type==0x8)
            Files.push_back(DirEntry->d_name);

    if(Files.size()==0)
        throw new Exceptions::Exception("No translation file found",__LINE__,__FILE__);

    return Files;
}

void Translate::TranslateEngine::SetLanguage(string CodeOfLanguage)
{
    //TODO
}

vector<Translate::TranslateEngine::AviableTranslations> Translate::TranslateEngine::ReadHeaders(vector<string> Files)
{
    vector<AviableTranslations> Translations;
    vector<string>::iterator Moving = Files.begin();
    vector<string>::iterator End = Files.end();
    for(;Moving!=End;Moving++)
    {
        string FullPath = "./data/Translate/" + *Moving;
        ifstream OpenedFile(FullPath);
        string FirstLine;
        getline(OpenedFile,FirstLine);
        unsigned long Position = FirstLine.find(':');
        string ShortcutOfLanguage = FirstLine.substr(0,Position);
        string NameOfLanguage = FirstLine.substr(Position+1);
        AviableTranslations temp = {FullPath,ShortcutOfLanguage,NameOfLanguage};
        Translations.push_back(temp);
    }

    return Translations;
}









