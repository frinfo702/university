x = -10:0.1:10;
y = zeros(size(x));
y(x > 0) = x(x > 0);
y(x <= 0) = -x(x <= 0);
plot(x, y);
