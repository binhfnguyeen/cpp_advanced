function check(ele){
    if(ele.value ===""){
        ele.classList.remove("error");
        setTimeout(()=>ele.classList.add("error"), 5);
        return true;
    }
    return false;
}

function tinhBMI(){
    let a = document.getElementById("weight");
    let b = document.getElementById("height");
    let k=0;
    if(a!==null && b!==null){
        if(check(a)===true || b === true){
            return;
        }
        a = parseFloat(a.value);
        b = parseFloat(b.value);
        let bmi = a/(b*b);
        if(bmi<18.5){
            k = "Thieu can";
            document.getElementById("BMI").innerHTML = k;
        } else if(bmi <25){
            k = "Binh thuong";
            document.getElementById("BMI").innerHTML = k;
        } else if(bmi < 30){
            k = "Thua can";
            document.getElementById("BMI").innerHTML = k;
        } else {
            k = "Beo phi";
            document.getElementById("BMI").innerHTML = k;
        }
    }
}