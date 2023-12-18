N = size(vout_runnerPerspective, 4);
M = size(vout_topDownPerspective, 4);

% create the video writers with 60 fps
writerObj_runnerPerspective = VideoWriter('video_runnerPerspective_angle.avi');
writerObj_runnerPerspective.FrameRate = 60;

writerObj_topDownPerspective = VideoWriter('video_topDownPerspective_angle.avi');
writerObj_topDownPerspective.FrameRate = 60;

open(writerObj_runnerPerspective);
open(writerObj_topDownPerspective);
    
for i=1:N
    frame_runnerPerspective = im2frame(vout_runnerPerspective(:,:,:,i));
    writeVideo(writerObj_runnerPerspective, frame_runnerPerspective);
end
for i=1:M
    frame_topDownPerspective = im2frame(vout_topDownPerspective(:,:,:,i));
    writeVideo(writerObj_topDownPerspective, frame_topDownPerspective);
end

close(writerObj_runnerPerspective);
close(writerObj_topDownPerspective);