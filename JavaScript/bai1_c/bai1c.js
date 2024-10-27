function check(ele){
    if(ele.value ===""){
        ele.classList.remove("error");
        setTimeout(()=>ele.classList.add("error"), 5);
        return true;
    }
    return false;
}

function changeMoney(){
    let st = document.getElementById("money");
    let dv = document.getElementById("choice");
    
    if(st !== null && dv !==null){
        if(check(st) === true || check(dv)===true){
            return;
        }

        st = parseFloat(st.value);
        dv = dv.value;

        let k;
        switch(dv){
            case "usd": 
                k = st/22000;
                break;
            case "eur":
                k = st/26000;
                break;
            case "aud":
                k = st/16000;
                break; 
        }

        document.getElementById("kq").innerHTML = `${st} VND = ${k.toFixed(2)} ${dv.toUpperCase()}`
    }
}