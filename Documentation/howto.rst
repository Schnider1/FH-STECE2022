Writing Documentation (Sphinx, Doxygen)
=======================================

.. contents::
   :local:

Overview
--------

Crazy car documentation is twofold,

* **Source comments** are written in Doxygen style
  (https://www.doxygen.nl/). Directly in the header files, right next
  to the class or function that is documented.

  This documentation is straight up to point, and is supposed to cover
  the API of one class only. It is written in Doxygen's own `Markdown
  flavor <https://www.doxygen.nl/manual/markdown.html>`__.

* **Readable prose** is written in Sphinx's
  (https://www.sphinx-doc.org/) ``*.rst`` files. Unlike Doxygen
  documentation, Sphinx is a real documentation system with many
  features like cross references, inline images, etc.. You describe
  concepts there, like how several classes play together.

  Unlike Doxygen documentation, Sphinx files are written in
  `RestructuredText
  <https://www.sphinx-doc.org/en/master/usage/restructuredtext/index.html>`__. Similar
  to markdown, but different.

Breathe (https://breathe.readthedocs.io/), a Sphinx extension, acts as
the bridge between both tools, and allows us to embed Doxygen
documentation in the Sphinx-massaged main documentation system.
   
Sphinx Installation
-------------------

.. sidebar:: See also

   * :doc:`jfasch:trainings/material/soup/python/swdev/venv/screenplay`
   * :doc:`jfasch:trainings/material/soup/python/swdev/pip/slides`
   * :doc:`jfasch:trainings/material/soup/python/swdev/pip/screenplay`

Create a virtual environment only for this installation. Sphinx has
many dependencies, and we don't want to install those globally. If on
Debian/Ubuntu, you might have to install the ``python3-venv`` package.

.. code-block:: console
   :caption: Debian

   $ sudo apt install python3-venv

.. code-block:: console

   $ python -m venv ~/My-Environments/FH-STECE2022/

Activate the environment,

.. code-block:: console

   $ . ~/My-Environments/FH-STECE2022/bin/activate
   (FH-STECE2022) $          # <-- note the modified prompt

Install project's dependencies (Sphinx's own extensions, and Breathe)
into that environment.

.. code-block:: console

   (FH-STECE2022) $ python -m pip install -r ~/My-Projects/FH-STECE2022/requirements.txt

Doxygen Installation
--------------------

.. code-block:: console

   $ apt install doxygen

Building (And Viewing) Documentation Locally
--------------------------------------------

Documentation is built automatically, as a sideeffect of the software
build. The project's ``Documentation/`` subdirectory contains CMake
code to invoke Sphinx (if installed) as part of the build. All you
need to do is to install Spinx and Doxygen in a virtual environment,
as shown above, and to have that environment activated during the
:doc:`software build <development>`.

.. note::

   To use the Sphinx installation that we just created, you have to
   have the virtual environment activated as described above.

.. code-block:: console

   (FH-STECE2022) $ pwd
   /home/jfasch/My-Builds/FH-STECE2022-x86_64/

   (FH-STECE2022) $ make
   ... roedel ...

The root HTML file (the "homepage", if you want) is then available in
``/home/jfasch/My-Builds/FH-STECE2022-x86_64/Documentation/sphinx/html/index.html``.

.. code-block:: console

   $ firefox /home/jfasch/My-Builds/FH-STECE2022-x86_64/Documentation/sphinx/html/index.html 

.. note::

   I can imaging that this (starting the Linux browser binary) works
   on :doc:`WSL
   <jfasch:trainings/material/soup/linux/basics/intro/wsl>` too.

   If not, you'd have to find yourself a way to point the Windows
   browser into the WSL/Ubuntu root filesystem. See
   :doc:`jfasch:trainings/material/soup/linux/basics/intro/wsl`.

Build Instabilities
...................

Shinx integration into the CMake is not airtight. Sometimes errors
won't go away. For example if you renamed one ``.rst`` file then the
build system will complain that the old file is not there anymore.

In this case it is advisable to simple remove the ``Documentation/`` build directory,

.. code-block:: console

   $ rm -r /home/jfasch/My-Builds/FH-STECE2022-x86_64/Documentation/

Note that markup errors won't go away so easily :-)
