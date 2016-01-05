x1 = hw_all-mean(hw_all);
x2 = mid-mean(mid);
x = [x1, x2];
u1 = x1/((x1'*x1)^(1/2));
u2 = x2/((x2'*x2)^(1/2));
u = [u1, u2];
c = u'*u;
