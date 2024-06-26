/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const res = {};
    for(let a of arr1){
        res[a.id] = a;
    }
    for(let a of arr2){
        if(!res[a.id]){
            res[a.id] = a;
        }
        else{
            res[a.id] = {...res[a.id], ...a.id};
        }
    }
    return Object.values(res);
};
