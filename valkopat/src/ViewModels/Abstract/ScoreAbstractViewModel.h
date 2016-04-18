#ifndef CERVISEMESTRALKA_SCOREABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_SCOREABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class ScoreAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        ScoreAbstractViewModel(Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~ScoreAbstractViewModel()
        { }
    };
}
#endif //CERVISEMESTRALKA_SCOREABSTRACTVIEWMODEL_H
