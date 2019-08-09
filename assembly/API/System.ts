

// support all the things someday
export enum SystemArchitecture {
    x86
}

export enum SystemFormFactor {
    phone,
    tablet,
    desktop,
    tv,
    voiceOnlyDevice
}


export default interface System {
    architecture: SystemArchitecture;
    formFactor: SystemFormFactor;
}