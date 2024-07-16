import cv2


image = cv2.imread('exno11.jpeg')


gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)


contours, _ = cv2.findContours(gray, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)


contour_image = image.copy()
cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2)


cv2.imshow('Image with Contours', contour_image)

cv2.waitKey(0)
cv2.destroyAllWindows()