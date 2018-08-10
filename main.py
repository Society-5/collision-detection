import numpy
import keras
print (keras.__version__)
from keras.models import Sequential
from keras.layers import Dense

classifier = Sequential ()

classifier.add (Dense (activation="relu", input_dim=8, units=64, kernel_initializer="uniform"))
classifier.add (Dense (activation="relu", units=16, kernel_initializer="uniform"))
classifier.add (Dense (activation="relu", units=4, kernel_initializer="uniform"))
classifier.add (Dense (activation="sigmoid", units=2, kernel_initializer="uniform"))

classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])

with open ('./training/in_filtered', 'r') as content_file:
    x_train = numpy.matrix (content_file.read ())

with open ('./training/out', 'r') as content_file:
    y_train = numpy.matrix (content_file.read ())

print (x_train, y_train)
classifier.fit(x_train, y_train, batch_size = 10, epochs = 171, verbose=2)

y_pred = classifier.predict ( x_train [0] )
print (y_pred)

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test, y_pred)
print (cm)
