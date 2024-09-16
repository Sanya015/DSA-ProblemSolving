#include <bits/stdc++.h> 

// T.C.=O(2N) S.C.=O(1)

int findCelebrity(int n) {
	int up=0;
	int down=n-1;
	while(up<down){
		if(knows(up, down)) up++;
		else if(knows(down, up)) down--;
		else{
			up++; down--;
		}
	}	
	 
	if(up==down){
		bool celeb=true;
		for(int i=0; i<n; i++){
			if(i!=up && knows(up, i)) celeb=false;
			if(i!=up && !knows(i, up)) celeb=false;
		}
		if(celeb) return up;
		
	}
	return -1;
}
