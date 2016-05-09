#include "LanguageConsoleViewModel.h"
#ifdef USE_CONSOLE

int ViewModel::LanguageConsoleViewModel::ShowMenu(std::map<int,LanguageOverwiew> LanguagesToChoose, std::map<int,string> Entries) const
{
    using namespace std;
    while(true)
    {
        map<int, int> Keys;
        int Index = 1;
        int UserChoice;
        for_each(LanguagesToChoose.begin(), LanguagesToChoose.end(),
                 [&Index, &Keys, this](pair<int, LanguageOverwiew> Input) {
                     cout << Index << ": " << this->Translation->GetTranslation("ChangeLanguageTo") << " "
                     << Input.second.Shortcut << '_' << Input.second.Name << endl;
                     Keys.insert(pair<int, int>(Index++, Input.first));
                 });

        for_each(Entries.begin(),Entries.end(),[&Index,&Keys,this](pair<int,string> Input){
            cout << Index << ": " << this->Translation->GetTranslation(Input.second) << endl;
            Keys.insert(pair<int, int>(Index++, Input.first));
        });

        cout << Translation->GetTranslation("ChoiceFromUser") << ": ";
        cin >> UserChoice;

        if(!(cin) || Keys.find(UserChoice)==Keys.end())
        {
            cin.clear();
            cin.ignore();
            cout << Translation->GetTranslation("WrongEntry") << endl;
        }
        else
            return Keys.at(UserChoice);
    }
}

ViewModel::LanguageConsoleViewModel::LanguageConsoleViewModel(const Translate::TranslateEngine* Translate)
        : LanguageAbstractViewModel(Translate)
{ }

void ViewModel::LanguageConsoleViewModel::ShowInfo() const
{
    using namespace std;
    cout << Translation->GetTranslation("LabelActualActivatedLanguage") << ": " << Translation->GetActualLanguage() << endl;
}


#endif
