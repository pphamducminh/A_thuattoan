void floyd(){
    for (int k=1; k<=n+9; k++){
        for (int i=1; i<=n+9; i++){
            for (int j=1; j<=n+9; j++){
                if (luu[i][j]>luu[i][k]+luu[k][j]){
                    luu[i][j] = luu[i][k]+luu[k][j];
                }
            }
        }
    }
}
