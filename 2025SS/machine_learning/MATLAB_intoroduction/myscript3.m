x = -10:0.1:10;
for xx = 1:length(x)
    if x(xx)>0
        y(xx) = x(xx);
    else
        y(xx) = -x(xx);
    end
end
plot(x, y)
