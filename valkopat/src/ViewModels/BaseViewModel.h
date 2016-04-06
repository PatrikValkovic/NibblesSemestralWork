#ifndef CERVISEMESTRALKA_BASEVIEWMODEL_H
#define CERVISEMESTRALKA_BASEVIEWMODEL_H

namespace ViewModel
{
    class BaseViewModel
    {
    public:
        virtual ~BaseViewModel()
        { }

        virtual void ShowSplashScreen() = 0;
        virtual const char* GetNameofViewModel() = 0;
    };
}

#endif //CERVISEMESTRALKA_BASEVIEWMODEL_H
