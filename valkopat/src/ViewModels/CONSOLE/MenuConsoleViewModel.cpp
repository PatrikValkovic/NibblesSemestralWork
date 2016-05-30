#include "MenuConsoleViewModel.h"
#ifdef USE_CONSOLE

int ViewModel::MenuConsoleViewModel::ShowMenu(std::vector<ViewModel::MenuAbstractViewModel::MenuEntry> VectorWithMenu)
{
    using std::vector;
    using std::cout;
    using std::endl;

    vector<ViewModel::MenuAbstractViewModel::MenuEntry>::iterator Moving = VectorWithMenu.begin();
    vector<ViewModel::MenuAbstractViewModel::MenuEntry>::iterator End = VectorWithMenu.end();
    while (true)
    {
        int Index = 1;
        int Choice;
        for (; Moving != End; Moving++)
            cout << Index++ << ": " << this->Translation->GetTranslation(Moving->Text) << endl;
        cout << this->Translation->GetTranslation("ChoiceFromUser") << ":";
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cin >> Choice;
        try
        {
            return VectorWithMenu.at((unsigned long)(Choice - 1)).index;
        }
        catch (out_of_range e)
        {
            cout << this->Translation->GetTranslation("WrongEntry") << endl;
        }
    }
}

ViewModel::MenuConsoleViewModel::MenuConsoleViewModel(const Translate::TranslateEngine* Translate)
        : MenuAbstractViewModel(Translate)
{ }


#endif
