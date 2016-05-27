#ifndef CERVISEMESTRALKA_ENUMS_H
#define CERVISEMESTRALKA_ENUMS_H

namespace Game
{
    enum Actions
    {
        MoveUp,
        moveRight,
        MoveDown,
        MoveLeft,
        Pause
    };

    enum Keys
    {
        NONE,
        KeyA,
        KeyB,
        KeyC,
        KeyD,
        KeyE,
        KeyF,
        KeyG,
        KeyH,
        KeyI,
        KeyJ,
        KeyK,
        KeyL,
        KeyM,
        KeyN,
        KeyO,
        KeyP,
        KeyQ,
        KeyR,
        KeyS,
        KeyT,
        KeyU,
        KeyV,
        KeyW,
        KeyX,
        KeyY,
        KeyZ,
        Key0,
        Key1,
        Key2,
        Key3,
        Key4,
        Key5,
        Key6,
        Key7,
        Key8,
        Key9
    };

    enum ServerActions
    {
        Hello = 88926,
        RequiredMap = 46722,
        MapTransfer = 38719,
        NameSending = 55216,
        InitSetting = 92397,
        PlayerTransfer = 69886,
        PlayerConnected = 37330,
        StartGame = 89360,
        KeyStroke = 70410,
        Wait = 29377,
        QuitGame = 22333
    };
}

#endif //CERVISEMESTRALKA_ENUMS_H
