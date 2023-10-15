 < high){
        mid = low + high; mid = mid/2;
        cout << low << " " << high << endl;
        if(possible(mid)){
            low = mid +1;
        }else{
            high = mid - 1;
        }
    }
    cout <<mid << endl;
    cout << n << "   "<< k << endl;
