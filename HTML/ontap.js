function kiemtra_songuyento(x){
    if(x<=1) return false;
    for(let i=2; i<=Math.sqrt(x); i++){
        if(x%i===0){
            return false;
        }
    }
    return true;
}

function thongke_mang(n){
    let mang = [];
    let snt=0;
    for(let i=0; i<n; i++){
        mang.push(Math.floor(Math.random()*100)+1);
    }
    for(let i=0; i<n;i++){
        if(kiemtra_songuyento(mang[i])){
            snt++;
        }
    }
    window.alert(snt);
}

thongke_mang(10);