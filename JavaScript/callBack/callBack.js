//Call back function
Array.prototype.map2 = function(callBack){
    var output=[], myLength = this.length;
    for(var i=0; i<myLength; i++){
       var result = callBack(this[i], i);
       output.push(result);
    }
    return output;
}
var courses = [
    'Javascript',
    'PHP',
    'Ruby'
];

var htmls = courses.map2(function(course){
    return `<h2>${course}</h2>`;
})

console.log(htmls.join(''));
// courses.map(function(course){
//     console.log(course);
// });

//forEach
// courses.forEach(function(course, index, array){
//     console.log(course, index, array);
// })

// Array.prototype.forEach2 = function(callBack){
//     for(var index var this){

//     }
// }

