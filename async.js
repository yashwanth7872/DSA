
const netWorkRequest = ()=>{
    setTimeout( ()=>{
        console.log('Async Code');
    },2000);
};

const netWorkrequest = ()=>{
    setTimeout( ()=>{
        console.log('Async 1sec Code');
    },3000);
};
console.log("Hello World");

netWorkRequest();

console.log("Done");

netWorkrequest();

console.log("Next Done")