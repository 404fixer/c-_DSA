for (int i = 0; i < ones.size(); i++)
    {
        auto itr2 = upper_bound(zero.begin(), zero.end(), ones[i]);
        if (itr2 == zero.begin())
            count += abs(ones[i] - *(itr2));
        else
        {
            if (abs(ones[i] - *(itr2)) < abs(ones[i] - *(itr2 - 1)))
            {
                count += abs(ones[i] - *(itr2));
            }
            else
            {
                count += abs(ones[i] - *(itr2--));
            }
        }
        zero.erase(itr2);
    }