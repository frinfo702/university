function z = g2_pdf(x, y, mu, Sigma)
a = 1 / (2*pi*sqrt(det(Sigma)));
v = [x;y] - mu;
z = a*exp(-1/2*v'*inv(Sigma)*v);
