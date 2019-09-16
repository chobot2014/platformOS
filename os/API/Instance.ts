import System from './System';

export enum InstanceState {
    on,
    off,
    inHibernation
}

// THIS IS DEFINED IN A ONE TO ONE WITH A SYSTEM AS DEFINED BY A HUMAN
// keep me tiny
export interface IInstance {
    system: System;
    systemUptime: Date;
    state: InstanceState;
}


// export default class Instance implements IInstance {
//     system: System;
//     systemUptime: Date;
//     state: InstanceState;
//     constructor() {

//     }


// }