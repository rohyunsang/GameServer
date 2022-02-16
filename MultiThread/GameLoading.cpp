bool isStillLoading;

Thread1
{
    isStillLoading = true;
    while (isStillLoading)
    {
        FrameWove();
        Render();
    }
}

Thread2
{
    LoadScene();
    LoadModel();
    LoadTexture();
    LoadAnimation();
    LoadSound();
    
    isStillLoading = false;
}
