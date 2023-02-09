#!/bin/bash
echo "46 primeiros bytes de input.wav"
hexyl -n 46 input.wav
echo "46 primeiros bytes de output.wav"
hexyl -n 46 output.wav
