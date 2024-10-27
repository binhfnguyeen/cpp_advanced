function validate(ele){
    if(ele.value === ""){
        ele.classList.remove("error");
        setTimeout(()=>ele.classList.add("error"), 5);
        return true;
    } 
    return false;
}

function giaiBac2(){
    let a = document.getElementById("aId");
    let b = document.getElementById("bId");
    let c = document.getElementById("cId");
    let k = 0;

    if(a!==null && b!==null && c!==null){
        if(validate(a) === true || validate(b) === true || validate(c) === true){
            return;
        }
        a = parseFloat(a.value);
        b = parseFloat(b.value);
        c = parseFloat(c.value);

        let delta = b*b-4*a*c;
        if(a===0 && b===0 && c===0){
            k = "Phuong trinh vo so nghiem!";
            document.getElementById("kq").innerHTML = k;
        } else
        if(delta < 0){
            k ="Phương trình vô nghiệm!";
            document.getElementById("kq").innerHTML = k;
        } else if (delta > 0){
            let x1 = -b*b + Math.sqrt(delta)/2*a;
            let x2 = -b*b - Math.sqrt(delta)/2*a;
            k = "Phương trình có 2 nghiệm phân biệt: x1= " + x1 + " và x2= " + x2;
            document.getElementById("kq").innerHTML = k;
        } else {
            let x = -b/2*a;
            k = "Phương trình có nghiệm kép: " + x;
            document.getElementById("kq").innerHTML = k;
        }
    }
}