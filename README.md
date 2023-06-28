# CUDA_Box-filter

> This repository has been created for college assignments in the Advanced Computer Architecture subject during the summer semester of 2022/2023.

## Exercises

- [Exercise 1 - CPU threads](exercise-1/README.md)
- [Exercise 2 - Thread synchronization and mutex](exercise-2/README.md)

## Project

Project is demonstrating implementation of the box filter at

- CPU
- GPU (with and without shared memory usage).

Also, CPU/GPU speed comparison is build automatized with python script and filter results are asserted using checksum.

Project is written in form of Jupyter Notebook and developed by using Google Colab GPU.

👉 [Project Notebook](./project/CUDA_Project_2023.ipynb)

Following 4 images demonstrate filter usage.

<table style="text-align:center">
  <tr>
    <td>
    <p>Original</p>
      <img title="Original" src="project/img/original.jpg" />
    </td>
    <td>
      <p>Filter radius 4 px</p>
      <img title="Filter radius 4 px" src="project/img/4px-filter.jpg" />
    </td>
  </tr>
  <tr>
    <td>
      <p>Filter radius 7 px</p>
      <img title="Filter radius 7 px" src="project/img/7px-filter.jpg" />
    </td>
    <td>
      <p>Filter radius 14 px</p>
      <img title="Filter radius 14 px" src="project/img/14px-filter.jpg" />
    </td>
</tr>
</table>
