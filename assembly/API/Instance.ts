
export enum InstanceState {
    on,
    off,
    inHibernation    
}

// represents the most root type of the running system
// keep me tiny
export default interface Instance {
    system: MediaKeySystemAccess;
    systemUptime: Date;
    state: InstanceState;
}