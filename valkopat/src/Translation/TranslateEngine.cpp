#include "TranslateEngine.h"

Translate::TranslateEngine::TranslateEngine(string DefaultLanguage)
{
    this->TranslationFiles = GetTranslateFiles();
    this->Aviable = this->ReadHeaders(this->TranslationFiles);
    this->SetLanguage(DefaultLanguage);
}

string Translate::TranslateEngine::GetTranslation(string OriginalName) const
{
    const map<string, string>::const_iterator iterator = this->TranslationForCurrentLanguage.find(OriginalName);
    if (iterator == TranslationForCurrentLanguage.end())
        throw new Exceptions::InvalidArgumentException("Translation not found for " + OriginalName,
                                                       __LINE__, __FILE__);
    return iterator->second;
}

vector<string> Translate::TranslateEngine::GetTranslateFiles() const
{
    DIR* DataDirectory = opendir("./data/Translate");
    if (DataDirectory == NULL)
        throw new Exceptions::Exception("Directory for translation not found", __LINE__, __FILE__);
    vector<string> Files;
    struct dirent* DirEntry;
    while ((DirEntry = readdir(DataDirectory)) != NULL)
        if (DirEntry->d_type == 0x8)
            Files.push_back(DirEntry->d_name);

    closedir(DataDirectory);

    if (Files.size() == 0)
        throw new Exceptions::Exception("No translation file found", __LINE__, __FILE__);

    return Files;
}

void Translate::TranslateEngine::SetLanguage(string CodeOfLanguage)
{
    vector<AviableTranslations>::iterator Moving = this->Aviable.begin();
    vector<AviableTranslations>::iterator End = this->Aviable.end();
    for (; Moving != End; Moving++)
        if (Moving->Shortcut == CodeOfLanguage)
        {
            LoadTranslation(Moving->File);
            this->CurrentLangauge = CodeOfLanguage;
            return;
        }

    throw new Exceptions::InvalidArgumentException(
            "Translation for language " + CodeOfLanguage + " wasnt found", __LINE__, __FILE__);
}

vector<Translate::TranslateEngine::AviableTranslations>
Translate::TranslateEngine::ReadHeaders(vector<string> Files) const
{
    vector<AviableTranslations> Translations;
    vector<string>::iterator Moving = Files.begin();
    vector<string>::iterator End = Files.end();
    for (; Moving != End; Moving++)
    {
        string FullPath = "./data/Translate/" + *Moving;
        ifstream OpenedFile(FullPath);
        string FirstLine;
        getline(OpenedFile, FirstLine);
        unsigned long Position = FirstLine.find(':');
        string ShortcutOfLanguage = FirstLine.substr(0, Position);
        string NameOfLanguage = FirstLine.substr(Position + 1);
        AviableTranslations temp = {FullPath, ShortcutOfLanguage, NameOfLanguage};
        Translations.push_back(temp);
    }

    return Translations;
}

void Translate::TranslateEngine::LoadTranslation(string Filename)
{
    ifstream File(Filename);
    string Line;
    this->TranslationForCurrentLanguage.clear();

    while (getline(File, Line))
    {
        unsigned long Position = Line.find(':');

        if (Position == string::npos)
            throw new Exceptions::InvalidFormatException("Invalid format of translate file " + Filename, __LINE__, __FILE__);

        string Key = Line.substr(0, Position);
        string Translation = Line.substr(Position + 1);
        this->TranslationForCurrentLanguage.insert(this->TranslationForCurrentLanguage.begin(),
                                                   pair<string, string>(Key, Translation));
    }
}

map<string, string> Translate::TranslateEngine::GetAviablesLanguages() const
{
    map<string, string> Languages;
    vector<AviableTranslations>::const_iterator Moving;
    for (Moving = this->Aviable.begin(); Moving != this->Aviable.end(); Moving++)
        Languages.insert(Languages.begin(), pair<string, string>(Moving->Shortcut, Moving->LanguageName));
    return Languages;
}

string Translate::TranslateEngine::GetActualLanguage() const
{
    return this->GetTranslation(this->CurrentLangauge);
}















