/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const res = Array(functions.length);
        let count = 0;

        for(let i = 0; i < functions.length; i++){

            functions[i]().then((result) => {
                res[i] = result;
                count++;
                if(count == functions.length) resolve(res);
            }).catch(reject);

        }

    })

};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
