#ifndef CERVISEMESTRALKA_VIEWMODELDERIVATINGCLASS_H
#define CERVISEMESTRALKA_VIEWMODELDERIVATINGCLASS_H
#include "../../Translation/TranslateEngine.h"


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
