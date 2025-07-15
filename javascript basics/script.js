//This is a single line comment
/*Multiline comment
alert("hello")
alert("hi")
*/
document.write("Hello,good evening")
var fname="jithin"
console.log(fname)
let age=19
console.log(age)
console.log(typeof(age))

let salary=40000.5
console.log(salary)

const pi=3.14
//pi=3.1415-cannot reassign
let canVote=false
console.log(canVote)
let e
console.log(e)
console.log(typeof(e))

let f=null
console.log(f)

const fav_colors=['pink','purple','white']
console.log(fav_colors)
console.log(fav_colors[0])
console.log(fav_colors[1])
console.log(fav_colors[2])
console.log(fav_colors[3])
console.log(fav_colors.length)

let fav_days=[]
fav_days[0]="sunday"
fav_days[1]="monday"
fav_days[2]="tuesday"
fav_days[3]="wednesday"
fav_days[4]="thursday"
fav_days[5]="friday"
fav_days[6]="saturday"
console.log(fav_days)
console.log(fav_days.length)

//object
const car={
    name:"BMW M8",
    color:"black",
    weight:1653

}
console.log(car)
console.log(car.name)
console.log(car.color)
console.log(car.weight)

console.log(10**3)
let a=10
let b=10

let result
result=a/b
console.log(result)

result=a%b
console.log(result)

let c=20
c/=50
console.log(c)

let x=5
console.log(x=="5")
console.log(x==="5")
console.log(x!="5")
console.log(x<5)
console.log(x>=5)

let x1=6
let y1=3
console.log(x1<10 && y1>5)
console.log(x1<10 || y1>5)
console.log(!(x1==y1))

let temperature =17
if(temperature>25){
    console.log("its hot outside")
}
else if(temperature>15){
    console.log("its warm outside")
}
else if(temperature>10){
    console.log("its cold outside")
}
else{
    console.log("its very cold outside")
}

for(let i=0;i<=5;i++){
    console.log(i)
}
function greet(){
    console.log("hello user")
}

greet()
function welcome(name){
    console.log("hello "+name)
}

welcome("jithin")

function add(num1,num2){
    return num1+num2
}
let sum=add(5,7)
console.log(sum)

let head1=document.getElementById("head")
head1.innerText="you have been hacked !!! :)"
head1.style.backgroundColor='rgb(89,161,201)'
head1.style.border='3px solid green'

const handleClick=()=>{
    document.getElementById('clickbutton').innerText="clicked"
    document.getElementById('clickbutton').style.
    backgroundColor='yellow'
    
}
document.getElementById('clickbutton').addEventListener=("click",handleClick)
document.getElementById('clickbutton').addEventListener("click",()=>console.log("second handler"))

