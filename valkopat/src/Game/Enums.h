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
        Hello = 0x12121212,
        RequiredMap = 0x24242424,
        MapTransfer = 0x38383838,
        NameTransfer = 0x54545454,
        InitTransfer = 0x16161616,
        PlayerTransfer = 0x53535353,
        PlayerConnected = 0x47474747,
        ActionsSend = 0x58585858,
        StartGame = 0x76767676,
        KeyStroke = 0x39393939,
        Wait = 0x46464646,
        InvalidRequest = 0x59595959
    };
}

#endif //CERVISEMESTRALKA_ENUMS_H
