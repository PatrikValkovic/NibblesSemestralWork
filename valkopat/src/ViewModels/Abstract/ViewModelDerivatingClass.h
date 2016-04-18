#ifndef CERVISEMESTRALKA_VIEWMODELDERIVATINGCLASS_H
#define CERVISEMESTRALKA_VIEWMODELDERIVATINGCLASS_H
#include "ViewModelDerivatingClass.h"


namespace ViewModel
{
    class ViewModelAbstractClass
    {
    public:
        ViewModelAbstractClass(Translate::TranslateEngine* Translate)
                : Translation(Translate)
        { }

        virtual ~ViewModelAbstractClass()
        { }

    private:
        Translate::TranslateEngine* Translation;
    };
}

#endif //CERVISEMESTRALKA_VIEWMODELDERIVATINGCLASS_H
