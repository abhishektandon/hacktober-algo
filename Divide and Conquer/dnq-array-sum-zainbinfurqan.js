let array = [1, 2, 3, 4, 5, 6];
console.log(array)

const half = Math.ceil(array.length / 2);
const firstHalf = array.splice(0, half)
const secondHalf = array.splice(-half)
let sum = 0;
firstHalf.map(item => {
    sum = sum + item
})
secondHalf.map(item => {
    sum = sum + item
})
console.log(sum)