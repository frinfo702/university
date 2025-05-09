clear all
mu = [0;0];
Sigma = [2 1; 1 2];
x = [-3:0.1:3];
y = [-3:0.1:3];
for xx = 1:length(x)
    for yy = 1:length(y)
        z(xx, yy) = g2_pdf(x(xx), y(yy), mu, Sigma);
    end
end

figure(1);
clf
surf(x, y, z);
view(45, 60)
print -djpeg gauss2d_pdf_surf.jpeg

figure(2);
clf
contour(x, y, z);
print -djpeg gauss2d_pdf_contour.jpeg
