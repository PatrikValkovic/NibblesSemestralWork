#ifndef CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H

namespace ViewModel
{
    class SplashScreenAbstractViewModel
    {
    public:
        virtual ~SplashScreenViewModel()
        { }

        virtual void ShowSplashScreen() = 0;
    };
}

#endif //CERVISEMESTRALKA_SPLASHSCREENABSTRACTVIEWMODEL_H
