# collision-detection

A small Keras neural network that decides from a camera observation whether the robot is about to collide. It is a learned alternative to the hand-written "QR code near the bottom of the frame" rule in [Mapping](https://github.com/Society-5/Mapping).

## Model

A fully connected binary classifier:

```
Dense(64, relu, input_dim=8) → Dense(16, relu) → Dense(4, relu) → Dense(2, sigmoid)
```

It is trained with Adam and binary cross-entropy (batch size 10, 171 epochs).

## Data

| File | Contents |
|---|---|
| `training/in` | Raw samples, 8 integers per row (these appear to be the x/y coordinates of the four corners of a detected QR code) |
| `training/in_filtered` | Cleaned version of `in`, used for training |
| `training/out` | One-hot labels per row (`1 0` / `0 1`): collision ahead vs. clear |
| `training/invert.py` | Helper that flips 0/1 labels |

## Run

```bash
pipenv install
pipenv run python main.py
./plot.sh    # trains, then plots the per-epoch loss with Octave (plot_error.m)
```

There is no separate test set yet, so the confusion-matrix step at the end of `main.py` is unfinished.

---

Part of **[Society-5](https://github.com/Society-5)**: a WowWee Robosapien X that explores a floor on its own, using a phone camera and QR codes as markers, with a mixed-reality (VR) interface for remote control. See [Introduction](https://github.com/Society-5/Introduction) for the project overview.
