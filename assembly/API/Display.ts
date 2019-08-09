import Interface from "./Interface";

export enum DisplayLocation {
    primary,
    attached,
    remote
}

export interface DisplaySize {
    pixels: Array<Array<number>>;
    millimeters: Array<Array<number>>;
}

export interface DisplayData {
    size: DisplaySize;
}

export interface DisplayState {
    currentData: DisplayData;
}

export default interface Display extends Interface {
    refreshRatePerSecond: number;
    displayLocation: DisplayLocation;    
    currentState: DisplayState;
}