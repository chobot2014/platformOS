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
    children: Array<Display>;    
}

export default interface Display {
    refreshRatePerSecond: number;
    displayLocation: DisplayLocation;
    currentState: DisplayState;
}