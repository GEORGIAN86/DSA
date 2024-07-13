        
        
        // This approach is useful when you want to sort one vector (ids)
        //  based on the values in another vector (positions), maintaining 
        // the relationship between the two.
        
        auto compare = [&](int id1, int id2){
            return positions[id1] <= positions[id2];
        };
        sort(ids.begin(), ids.end(), compare);